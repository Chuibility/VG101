function PasTri2(n)
    fid=fopen('PasTri2.txt','wt');
    space=5; % The space between the center of two numbers (must be odd since symmetric)
    for i=0:n-1
        fprintf(fid,'%s',blanks((n-i-1)*floor(space/2+1))); % Print the blanks before the first number
        for j=0:i
            num=nchoosek(i,j);
            digit=floor(log10(num)); % Get the digits of the number
            str=[blanks(floor(space/2-(digit-1)/2)) num2str(num)]; % Add blanks before the number
            fprintf(fid,['%-' num2str(space+1) 's'],str);% Print the number with fixed width
        end
        fprintf(fid,'\n');
    end
end

