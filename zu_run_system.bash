./a.out
cd zw_InitCoords
ls | sort > times
cd ../
Rscript PlotCoords.R
cd zv_Coords_Images
bash makeVideo.bash
vlc out.mp4
