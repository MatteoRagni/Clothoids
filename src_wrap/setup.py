from distutils.core import setup
from distutils.extension import Extension

G2lib = Extension(
    'G2lib',
    sources=['LineSegmentWrap.cc'],
    library_dirs=['../lib'],
    include_dirs=['../lib/include'],
    extra_compile_args = ['-std=c++11'],
    libraries=['boost_python37-mt', 'Clothoids'],
)

setup(
    name='G2lib',
    version='0.1',
    ext_modules=[G2lib])