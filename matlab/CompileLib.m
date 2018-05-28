clc;
clear functions;

NAMES = { ...
  'FresnelCS', ...
  'LineSegmentMexWrapper', ...
  'CircleMexWrapper', ...
  'BiarcMexWrapper', ...
  'ClothoidCurveMexWrapper', ...
  'buildClothoid2arcG2', ...
  'buildClothoid3arcG2', ...
} ;

LIBS = [ ...
  '-I../src ' ...
  '../src/G2lib.cc ' ...
  '../src/Line.cc ' ...
  '../src/Circle.cc ' ...
  '../src/Biarc.cc ' ...
  '../src/Clothoid.cc ' ...
  '../src/ClothoidDistance.cc ' ...
  '../src/ClothoidG1.cc ' ...
  '../src/ClothoidG2.cc ' ...
  '../src/CubicRootsFlocke.cc ' ...
  '../src/Fresnel.cc ' ...
  '../src/Triangle2D.cc ' ...
] ;

[~,mexLoaded] = inmem('-completenames') ;

disp('---------------------------------------------------------');
for k=1:length(NAMES)
  N=NAMES{k} ;
  fprintf(1,'Compiling: %s\n',N) ;

  CMD = [ 'while mislocked(''' N ''') ; munlock(''' N ''') ; end;'] ;
  eval(CMD);

  CMD = ['mex -output ../matlab/',N,' -largeArrayDims ../src_mex/mex_',N,'.cc ', LIBS] ;
  if isunix
    if ismac
      CMD = [CMD, ' -lstdc++ CXXFLAGS="\$CXXFLAGS -Wall -O2 -g0"'] ;
    else
      CMD = [CMD, ' -lstdc++ CXXFLAGS="\$CXXFLAGS -Wall -O2 -g0"'] ;
    end
  elseif ispc
  end
  disp(CMD);
  eval(CMD);
end
disp('----------------------- DONE ----------------------------');
