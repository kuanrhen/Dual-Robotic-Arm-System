P=[ 43.30, 255.00, 300.00;
    32.14, 241.70, 289.92;
   17.10, 233.02, 279.85;
    0.00, 230.00, 269.77;
    -17.10, 233.02, 259.69;
    -32.14, 241.70, 249.62;
    -43.30, 255.00, 239.54];

P_trans=transpose(P);

T_spline=[0 1.8 3 4 5 6.2 8];

x_spline=spline(T_spline,[0 P_trans(1,:) 0]);
y_spline=spline(T_spline,[0 P_trans(2,:) 0]);
z_spline=spline(T_spline,[0 P_trans(3,:) 0]);

tt_spline = 0:0.1:8;

data_x=ppval(x_spline,tt_spline);
data_y=ppval(y_spline,tt_spline);
data_z=ppval(z_spline,tt_spline);
%%
plot3(P_trans(1,:), P_trans(2,:), P_trans(3,:), 'k.');
xlabel('x');
ylabel('y');
zlabel('z');
view(90,90);
grid on;
grid minor;
hold on;
axis( [-50 50 200 300 210 320]);
plot3(data_x, data_y, data_z, 'r.');
plot3(P_trans(1,:), P_trans(2,:), P_trans(3,:), 'k.','MarkerSize',20);

%%
R1=[-0.866 0.5 0;
    -0.5 -0.866 0;
    0 0 1];
R2=[-0.643 0.766 0;
    -0.766 -0.643 0;
    0 0 1];
R3=[-0.342 0.94 0;
    -0.94 -0.342 0;
    0 0 1];
R4=[0 1 0;
    -1 0 0;
    0 0 1];
R5=[0.342 0.94 0;
    -0.94 0.342 0;
    0 0 1];
R6=[0.643 0.766 0;
    -0.766 0.643 0;
    0 0 1];
R7=[0.866 0.5 0;
    -0.5 0.866 0;
    0 0 1];

EUL_1=rotm2eul(R1,'ZYZ');
EUL_2=rotm2eul(R2,'ZYZ');
EUL_3=rotm2eul(R3,'ZYZ');
EUL_4=rotm2eul(R4,'ZYZ');
EUL_5=rotm2eul(R5,'ZYZ');
EUL_6=rotm2eul(R6,'ZYZ');
EUL_7=rotm2eul(R7,'ZYZ');




AGL_1=[EUL_1(1) EUL_2(1) EUL_3(1) EUL_4(1) EUL_5(1) EUL_6(1) EUL_7(1)];
AGL_2=[EUL_1(2) EUL_2(2) EUL_3(2) EUL_4(2) EUL_5(2) EUL_6(2) EUL_7(2)];
AGL_3=[EUL_1(3) EUL_2(3) EUL_3(3) EUL_4(3) EUL_5(3) EUL_6(3) EUL_7(3)];

T_angle=[0 1.8 3 4 5 6.2 8];
theta1_spline=spline(T_angle,[0 AGL_1 0]);
theta2_spline=spline(T_angle,[0 AGL_2 0]);
theta3_spline=spline(T_angle,[0 AGL_3 0]);

tt_angle=0.0:0.1:8;
data_theta1=ppval(theta1_spline,tt_angle);
data_theta2=ppval(theta2_spline,tt_angle);
data_theta3=ppval(theta3_spline,tt_angle);

EUL_AGL = [data_theta1;data_theta2;data_theta3];
EUL_AGL_TRANS = transpose(double(EUL_AGL));

for i=1:81
ORI(i,:,:)=eul2rotm(EUL_AGL_TRANS(i,:),'ZYZ');
end
%%
for i=1:1:81
plot3(P_trans(1,:), P_trans(2,:), P_trans(3,:), 'k.','MarkerSize',20);
axis( [-50 50 220 320 210 320]);
xlabel('x');
ylabel('y');
zlabel('z');
grid on;
grid minor;
%view(90,90);
hold on;
plot3(data_x, data_y, data_z, 'r.');
quiver3(repmat(data_x(i),3,1),repmat(data_y(i),3,1),repmat(data_z(i),3,1),transpose(ORI(i,:,1)),transpose(ORI(i,:,2)),transpose(ORI(i,:,3)),20,'g');
pause(0.01);
hold off;
end
%%
T_via=[ 0 1.8 3 4 5 6.2 8];
X=P_trans(1,:);
Y=P_trans(2,:);
Z=P_trans(3,:);

data_xx = diff(double(data_x));
data_yy = diff(double(data_y));
data_zz = diff(double(data_z));

data_xxx = diff(abs(data_xx));
data_yyy = diff(abs(data_yy));
data_zzz = diff(abs(data_zz));
%%
figure('NumberTitle', 'off', 'Name', 'X-Axis');
tiledlayout(3,1);
nexttile;
plot(T_via,X,'o');
hold on;
plot(0:0.1:8,data_x,'r');
xlabel('Time, second');
ylabel('Position');
grid on;
grid minor;

nexttile;
hold on;
plot(0.1:0.1:8,data_xx,'b');
xlabel('Time, second');
ylabel('Velocity');
grid on;
grid minor;

nexttile;
hold on;
plot(0.2:0.1:8,data_xxx,'g');
xlabel('Time, second');
ylabel('Acceleration');
grid on;
grid minor;

figure('NumberTitle', 'off', 'Name', 'Y-Axis');
tiledlayout(3,1);
nexttile;

plot(T_via,Y,'o');
hold on;
plot(0:0.1:8,data_y,'r');
xlabel('Time, second');
ylabel('Position');
grid on;
grid minor;

nexttile;
hold on;
plot(0.1:0.1:8,data_yy,'b');
xlabel('Time, second');
ylabel('Velocity');
grid on;
grid minor;

nexttile;
hold on;
plot(0.2:0.1:8,data_yyy,'g');
xlabel('Time, second');
ylabel('Acceleration');
grid on;
grid minor;

figure('NumberTitle', 'off', 'Name', 'Z-Axis');
tiledlayout(3,1);
nexttile;

plot(T_via,Z,'o');
hold on;
plot(0:0.1:8,data_z,'r');
xlabel('Time, second');
ylabel('Position');
grid on;
grid minor;

nexttile;
hold on;
plot(0.1:0.1:8,data_zz,'b');
xlabel('Time, second');
ylabel('Velocity');
grid on;
grid minor;

nexttile;
hold on;
plot(0.2:0.1:8,data_zzz,'g');
xlabel('Time, second');
ylabel('Acceleration');
grid on;
grid minor;
%%
desired_orientation=ORI(:,1,1)
desired_orientation=transpose(desired_orientation);
%%
for i=1:81
desired_orientation_rad(i)=acos(desired_orientation(i));
 desired_orientation_deg(i)= radtodeg(desired_orientation_rad(i));
end


