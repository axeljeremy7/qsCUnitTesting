a = rnorm(10, 50, 50/2)
b = rnorm(10, 30, 30/2)

A = rep(1,10)
B = -(a+b)
C = a*b

fileConn<-file("test.in1.txt")
txt = c()
for (i in 1:10){
  txt = c (txt, "y")
  txt =  c(txt, paste(c(A[i], B[i],C[i]), collapse = " "))
}
txt = c (txt, "n")
writeLines(txt, fileConn)
close(fileConn)
txt =  c(txt, paste(c(A[i]*10^7, B[i]*10^7,C[i]*10^7), collapse = " "))


fileConn2<-file("the_roots_calculated.txt")
txt2 = c()
for (i in 1:10){
  tmp = sort(c(b[i], a[i]))
  print(tmp)
  txt2 =  c(txt2,sprintf("%.7f %.7f", tmp[1], tmp[2]))
}
writeLines(txt2, fileConn2)
close(fileConn2)


# txt <- toString(a[1])

x=1:5
str=sprintf("hi %d %.7f",7, 6.98989890898)
str

quadsolver <- function(a,b, c) {
  r1 = (-b + sqrt(b^2 - 4*a*c))/(2*a)
  r2 = (-b - sqrt(b^2 - 4*a*c))/(2*a)
  return(c(r1,r2))
}

