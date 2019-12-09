from conans import ConanFile, CMake

class HelloLib(ConanFile):
    name = "hellolib"
    version = "0.1"

    settings = "os", "arc", "compiler", "build_type"
    options = {"shared": [True, False]}
    default_options = {"shared": False}

    generators = "cmake", "cmake_find_package"
    exports_sources = "include/*", "src/*"

    requires = "fmt/6.0.0"

    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.configure()
        return cmake
    
    def build(self):
        cmake = self._configure_cmake()
        cmake.build()
    
    def package(self):
        cmake = self._configure_cmake()
        cmake.install()
        self.copy("README.md", dst=".")
