function a_dec = Mybin2dec( a_bin, n )
    a_dec=0;
    for i=0:n-1
       a_dec=a_dec+(a_bin(n-i)-'0')*2^i;
    end
end

