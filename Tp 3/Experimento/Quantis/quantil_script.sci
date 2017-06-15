
function[] = Quantis(name)
    v = [10, 25, 50,  75, 90]
    M = csvRead(name,',', 'double');
    S = read_csv(name);
    tam = size(M);
    for i=0:(tam(1))/30 -1
        x = M(i*30+1:(i+1)*30, 3);
        vec = matrix(x,1, 30);
        var = perctl(vec, v);
        disp(S(i*30+1, 1) + " " + S(i*30+1, 2));
        for k=1:5
           printf("Quantil = %f     -> %f\n", v(k)/100, var(k)); 
        end
    end
endfunction
