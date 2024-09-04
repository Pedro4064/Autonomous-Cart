function A = A_Jacobian(x,u)
%A_Jacobian
%    A = A_Jacobian(X,X_DOT,X_DDOT,Y,Y_DOT,Y_DDOT,x(7),x(7),u(1),u(2))

%    This function was generated by the Symbolic Math Toolbox version 24.1.
%    03-Sep-2024 21:47:52

t2 = u(1)+u(2);
A = reshape([1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0./1.0e+1,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0./2.0e+2,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0./1.0e+1,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0./2.0e+2,0.0,1.0,0.0,0.0,0.0,t2.*sin(x(7)).*(-7.0./4.0e+2),0.0,0.0,t2.*cos(x(7)).*(7.0./4.0e+2),0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0./1.0e+1,0.0],[8,8]);
end