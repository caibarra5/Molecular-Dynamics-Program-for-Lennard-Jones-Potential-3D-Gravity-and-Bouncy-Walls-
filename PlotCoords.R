library(scatterplot3d)

axes_dim = scan("zs_region.txt")

setwd("./zw_InitCoords")



x <- scan("times", what="", sep="\n")
x = head(x,-1)

y = as.numeric(x)

z = data.frame(y,x)

# Here I can order by the y (as.numeric) column
z = z[order(y),]

# Need y to be linked to x in order to sort x since converting to numeric and back
# to string removes trailing 0s. So need a key and value(a dictionary). 
# The key will be the numeric value and the name the value.

sink("../zv_Coords_Images/mylist.txt")
for(time in z$x){
#  print(time)
  cat("file ",time,".jpeg\n",sep = "")
  r = read.table(time,col.names=c("x","y","z"))
  jpeg(file=paste("../zv_Coords_Images/",time,".jpeg",sep=""))
#  plot(r,main=time,xaxt='n',yaxt='n')
  scatterplot3d(r,main=time,xlim = c(-0.5*axes_dim[1],0.5*axes_dim[1]),ylim = c(-0.5*axes_dim[2],0.5*axes_dim[2]),zlim = c(-0.5*axes_dim[3],0.5*axes_dim[3]))
#  axis(side=1, at=seq(-0.5*axes_dim[1],0.5*axes_dim[1],axes_dim[1]/4))
#  axis(side=2, at=seq(-0.5*axes_dim[2],0.5*axes_dim[2],axes_dim[2]/4))
#  axis(side=3, at=seq(-0.5*axes_dim[3],0.5*axes_dim[3],axes_dim[3]/4))
  dev.off()
}
sink()

#r = read.table("0",col.names=c("x","y"))
#jpeg(file="saving_plot1.jpeg")
#plot(r,main="0")
#dev.off()
