#!/usr/bin/env python3

from setuptools import setup, Extension 
from Cython.Build import cythonize
import sys

if 'linux' in sys.platform or 'darwin' in sys.platform:
	# Linux / macOS
	compile_flags = ["-std=c11", "-O3", "-march=native"]
else:
	# Windows
	compile_flags = ["/std:c11", "/O2", "/arch:AVX2"]

ext = Extension(
		name = "OurLibrary",
		sources = ["src/our_wrapper.pyx", "src/our_simple_c_lib.c"],
		extra_compile_args = compile_flags
	)

# Use cythonize on the extension object.
setup(ext_modules=cythonize(ext, language_level="3"))