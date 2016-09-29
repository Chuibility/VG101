function PasTri(n)
    fid = fopen('PasTri.txt','wt');
    space=5; % The space between the center of two numbers (must be odd since symmetric)
    for i=0:n-1
        str='';
        for j=1:ceil(space/2)*(n-i-1)
            str=[str, ' ']; % Print the blanks before the first number
        end
        for j=0:i
            a=nchoosek(i,j);
            digit=floor(log10(a)); % Get the digits of the number
            for k=ceil(digit/2):floor(space/2)-mod(digit+1,2)
                str=[str, ' '];% Add blanks before the number
            end
            str=[str,num2str(a)];
            for k=ceil(digit/2):floor(space/2)
                str=[str, ' '];% Add blanks after the number
            end
        end
        fprintf(fid,'%s\n',str);
    end
    fclose(fid);
end