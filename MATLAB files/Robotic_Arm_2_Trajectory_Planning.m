t1=0:0.01:1.5;
y1=(40/3)*t1.^2-(160/27)*t1.^3;
plot(t1,y1);
xlabel('t');
ylabel('theta3');
grid on;
grid minor;
hold on;
plot(0,0,'k.','MarkerSize',15);
plot(1.5,10,'k.','MarkerSize',15);
axis([0 1.6 0 11]);
%%
t1=0:0.01:1.5;
y1=(80/3)*t1-(160/9)*t1.^2;
plot(t1,y1);
xlabel('t');
ylabel('Velocty or Acceleration');
grid on;
grid minor;
axis([0 1.6 -30 30]);
hold on;
y1=(80/3)-(320/9)*t1;
plot(t1,y1);
legend('Velocity','Acceleration','FontSize',15);
%%
t2=0:0.01:2;
y2=11.25.*t2.^2;
y22=22.5*t2;
y222=22.5;

t3=2.01:0.01:4;
y3=45+45*(t3-2);
y33=45;
y333=0;

t4=4.01:0.01:6;
y4=180-11.25*(6-t4).^2;
y44=22.5*(6-t4);
y444=-22.5;

plot(t2,y2,'r');
xlabel('t');
ylabel('Position');
axis( [0 6.5 0 190]);
grid on;
grid minor;
hold on;
plot(t3,y3,'b');
plot(t4,y4,'g');
plot(0,0,'k.','MarkerSize',20);
plot(6,180,'k.','MarkerSize',20);
legend('Segment 1','Segment 2','Segment 3','FontSize',20);
%%
plot(t2,y22,'r');
xlabel('t');
ylabel('Velocity');
 axis( [0 6.5 0 50]);
grid on;
grid minor;
hold on;
plot(t3,y33*ones(size(t3)),'b');
hold on;
plot(t4,y44,'g');
legend('Segment 1','Segment 2','Segment 3','FontSize',20);

%%
plot(t2,y222*ones(size(t2)),'r');
xlabel('t');
ylabel('Acceleration');
axis( [0 6.5 -25 25]);
grid on;
grid minor;
hold on;
plot(t3,y333*ones(size(t3)),'b');
hold on;
plot(t4,y444*ones(size(t4)),'g');
legend('Segment 1','Segment 2','Segment 3','FontSize',20);
%%
t5=0:0.01:1.5;
y5=10-(40/3)*t5.^2+(160/27)*t5.^3;
plot(t5,y5);
xlabel('t');
ylabel('Position');
grid on;
grid minor;
hold on;
plot(0,10,'k.','MarkerSize',15);
plot(1.5,0,'k.','MarkerSize',15);
axis([0 1.6 0 11]);

%%
t5=0:0.01:1.5;
y55=-(80/3)*t5+(160/9)*t5.^2;
plot(t5,y55);
xlabel('t');
ylabel('Velocty or Acceleration');
grid on;
grid minor;
%axis([0 1.6 -30 30]);
hold on;
y555=-(80/3)+(320/9)*t5;
plot(t5,y555);
legend('Velocity','Acceleration','FontSize',15);


