require 'active_support'
require 'know/ontology'
require 'rdf/turtle'
require 'stringio'

include ActiveSupport::Inflector, RDF

ActiveSupport::Inflector.inflections(:en) do |inflect|
  inflect.irregular 'cafe', 'cafes'
end

task default: %w(codegen)

HEADER = <<~EOF
  /* This is free and unencumbered software released into the public domain. */

  #pragma once
EOF

file 'src/know/classes.hpp' => %w(../know.ttl) do |t|
  ontology = Know::Ontology.load(t.prerequisites.first)
  File.open(t.name, 'w') do |out|
    out.puts HEADER
    out.puts
    ontology.classes.each do |klass|
      out.puts %Q[#include "classes/#{klass.cpp_file}"]
    end
  end
end

task :codegen => %w(../know.ttl src/know/classes.hpp) do |t|
  ontology = Know::Ontology.load(t.prerequisites.first)
  ontology.classes.each do |klass|
    filename = underscore(klass.name)
    File.open("src/know/classes/#{filename}.hpp", 'w') do |out_file|
      top, out = StringIO.new, StringIO.new
      includes = {}

      includes['cstdint'] = "for std::uint64_t"
      includes['ctime']   = "for std::time_t" # TODO
      includes['memory']  = "for std::shared_ptr"
      includes['string']  = "for std::string"
      includes['vector']  = "for std::vector"

      # Generate the `know::$CLASS` class definition:
      out.puts <<~EOF
        class know::#{klass.cpp_name} {
          using string = ::std::string;
          template<typename T> using shared_ptr = ::std::shared_ptr<T>;
          template<typename T> using vector = ::std::vector<T>;

        public:
      EOF
      klass.properties.each do |property|
        next if property.cpp_type.nil?
        out.puts "  #{property.cpp_type} #{property.cpp_name};"
      end
      out.puts unless klass.properties.empty?
      out.puts "  inline virtual ~#{klass.cpp_name}() = default;"

      # Generate the `know::$CLASS#clone()` method:
      out.puts
      out.puts <<~EOF.lines.each { |s| s.prepend(' '*2) }.join
        inline virtual shared_ptr<#{klass.cpp_name}> clone() const {
          auto clone = std::make_shared<#{klass.cpp_name}>();
      EOF
      klass.properties.each do |property|
        next if property.cpp_type.nil?
        out.puts <<~EOF.lines.each { |s| s.prepend(' '*4) }.join
          clone->#{property.cpp_name} = this->#{property.cpp_name};
        EOF
      end
      out.puts <<~EOF.lines.each { |s| s.prepend(' '*2) }.join
          return clone;
        }
      EOF

      out.puts "};"

      # Begin generating the file header:
      top.puts HEADER

      # Generate standard library dependencies:
      top.puts unless includes.empty?
      includes.each do |header, comment|
        header = "<#{header}>"
        top.puts "#include #{header.ljust(9)} // #{comment}"
      end

      # Generate internal dependencies:
      top.puts unless klass.dependencies.empty?
      klass.dependencies.each do |dependency|
        top.puts "#include \"#{dependency.cpp_name}.hpp\""
      end

      top.puts
      top.puts "namespace know {"
      top.puts "  class #{klass.cpp_name};"
      klass.dependencies.each do |dependency|
        top.puts "  class #{dependency.cpp_name};"
      end
      top.puts "}"
      top.puts

      out_file.write top.string
      out_file.write out.string
    end
  end
end

class Know::Ontology::Class
  def cpp_file
    "#{underscore(self.name.to_s)}.hpp"
  end

  def cpp_name
    case self.name
      when :Class then 'class_'
      else underscore(self.name.to_s)
    end
  end

  def cpp_type
    "know::#{self.cpp_name}"
  end
end

class Know::Ontology::Property
  def cpp_name
    name = underscore(self.name.to_s)
    name = pluralize(name) unless self.functional?
    name
  end

  def cpp_type
    type = case type = self.range
      when ::Know::Ontology::Class then "shared_ptr<know::#{type.cpp_name}>"
      when ::XSD.anyURI then 'string'
      when ::XSD.dateTime then 'std::time_t' # TODO
      when ::XSD.language then 'string'
      when ::XSD.nonNegativeInteger then 'std::uint64_t'
      when ::XSD.string then 'string'
      else return nil
    end
    type = "vector<#{type}>" unless self.functional?
    type
  end
end
