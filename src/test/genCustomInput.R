



a = rnorm(10, 50, 50/2)
b = rnorm(10, 30, 30/2)

A = rep(1,10)
B = -(a+b)
C = a*b

fileConn<-file("test.in.txt")
txt = c()
for (i in 1:10){
  txt =  c(txt, paste(c(A[i], B[i],C[i]), collapse = " "))
}
writeLines(txt, fileConn)
txt =  c(txt, paste(c(A[i]*10^7, B[i]*10^7,C[i]*10^7), collapse = " "))
close(fileConn)

fileConn2<-file("roots_test.in.txt")
txt2 = c()
for (i in 1:10){
  txt2 =  c(txt2,sprintf("%.6f %.6f", b[i], a[i]))
}
writeLines(txt2, fileConn2)
close(fileConn2)


# txt <- toString(a[1])

x=1:5
str=sprintf("hi %d %.7f",7, 6.98989890898)
str



