#rm temp

xargs -I {} mkdir -p "{}" < zw_cleaned_cpp_files_list.txt
