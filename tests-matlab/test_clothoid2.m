addpath('../matlab');

close all ;
clear all ;

% check constructors
x0     = 0 ;
y0     = 2 ;
theta0 = 0 ;
kappa0 = [-0.6, 1, 2, 10] ;
dk     = [0.2, 0.1, 0, -1] ;
L      = [10,5,10,10] ;


for kk=1:4
  subplot(2,2,kk) ;
  L1 = ClothoidCurve( x0, y0, theta0, kappa0(kk), dk(kk), L(kk) );
  %
  L1.plot(L/1000,'Color','green','LineWidth',3) ;
  hold on;

  x     = -10:0.05:10 ;
  y     = -5:0.05:15 ;
  [X,Y] = meshgrid(x,y);

  tic
  Z = L1.distance(X,Y);
  toc

  contour(X,Y,Z,100)
  %surf(X,Y,Z)
  axis equal;
  %
  L1.delete() ;
end