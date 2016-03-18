a=eye(2,2);b=ones(a);
save('val.dat',a,b);
clear a
clear b
load('val.dat','a','b');

// gravação seqüêncial em um arquivo
fd=mopen('TMPDIR/foo.bin','wb')
for k=1:4, x=k^2;save(fd,x,k),end
mclose(fd)
fd=mopen('TMPDIR/foo.bin','rb')
for i=1:4, load(fd,'x','k');x,k,end
mclose(fd)

// anexando variáveis a um arquivo gravado antigo
fd=mopen('TMPDIR/foo.bin','r+')
mseek(0,fd,'end') 
lst=list(1,2,3)
save(fd,lst)
mclose(fd)
