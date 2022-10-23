if [ $1 -eq 1 ]
then
  bash build.bash
fi

bash zt_clean.bash
bash zu_run_system.bash
