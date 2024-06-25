# See: https://docs.conan.io/2/reference/conanfile.html

from conan import ConanFile
from conan.tools.build import check_min_cppstd
from conan.tools.files import copy
from conan.tools.layout import basic_layout
from os import path

class KnowCppConan(ConanFile):
    name = "know.cpp"
    version = "0.0.0"
    description = "The Know Framework for C++."
    license = "Unlicense"
    author = "KNOW Project"
    topics = ("ontology", "header-only", "c++23")
    homepage = "https://github.com/KnowOntology/know.cpp"
    url = "https://github.com/KnowOntology/know.cpp.git"
    languages = "C++"
    exports_sources = "src/*"
    no_copy_source = True

    def layout(self):
        basic_layout(self, src_folder="src")

    def validate(self):
        #check_min_cppstd(self, 23) # FIXME: Conan 2.4.1 appears to be defective
        pass

    def export_sources(self):
        copy(self, "UNLICENSE", src=self.recipe_folder, dst=self.export_sources_folder)

    def build(self):
        pass

    def package(self):
        copy(self, "*.hpp", src=self.source_folder, dst=path.join(self.package_folder, "include"))
        copy(self, "UNLICENSE", src=self.export_sources_folder, dst=path.join(self.package_folder, "licenses"))

    def package_info(self):
        self.cpp_info.bindirs = []
        self.cpp_info.libdirs = []
