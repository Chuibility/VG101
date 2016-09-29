function a_bin = Mydec2bin( a_dec )
    a_bin='';
    while(a_dec~=0)
        if(mod(a_dec,2)==1)
            a_bin=['1',a_bin];
            a_dec=(a_dec-1)/2;
        else
            a_bin=['0',a_bin];
            a_dec=a_dec/2;
        end
    end
end


