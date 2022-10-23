setwd("/home/christopher/Dropbox/aeNotes/aaBooks/ag7_Molecular_Dynamics_with_Ex_Codes_564/fCodes/b_2_Basic_molecular_dynamics/aa_1_2D_SoftDisks_Simulation/a_C_version/a_one_directory_compilation/zx_InitVels")
v = read.table("0",col.names = c("v.x","v.y","mag"))

hist(v$v.x)

hist(v$v.y)

plot(v$v.x,v$v.y)

plot(v$mag)
