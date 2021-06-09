close all
clear all
clc

results = load('results3.txt');
figure(1)
% plot(results(:,3),results(:,2),'r*');
scatter(results(:,3),results(:,2),[],results(:,4))
hold on
USshape = load('USStateXY.txt');

colorbar

for i = 1:max(USshape(:,1))     
    subtable_inds = USshape(:,1) == i;     
    temp_inds = find(subtable_inds);     
    smallUSshape = USshape(temp_inds,:);     
    for i2 = 1:max(smallUSshape(:,2))            
        subtable_inds2 = smallUSshape(:,2) == i2;         
        temp_inds2 = find(subtable_inds2);         
        smallUSshape2 = smallUSshape(temp_inds2,:);         
        if length(smallUSshape2(:,3)) > 1           
            plot([smallUSshape2(:,3); smallUSshape2(1,3)], [smallUSshape2(:,4); smallUSshape2(1,4)],'b');           
        end
    end
end




%close all;

%calculated = load('results3.txt');

%y = calculated(:,2);
%x = calculated(:,3);
%t = calculated(:,4);

%scatter(x,y,30,t);

%title('Averge temp by lat an long');
%ylabel('Long');
%xlabel('Lat');


