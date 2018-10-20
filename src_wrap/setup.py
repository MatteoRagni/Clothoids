from distutils.core import setup
from distutils.extension import Extension

G2lib = Extension(
    'G2lib',
    sources=[
      'LineSegmentWrap.cc'
    ],
    include_dirs=['../lib/include'],
    extra_objects=['../lib/libClothoids.a'],
    extra_compile_args = ['-std=c++11'],
    libraries=['boost_python37-mt'],
)

setup(
    name='G2lib',
    version='0.1',
    ext_modules=[G2lib])