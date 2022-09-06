mkdir ~/RootFolder
date
sleep 3
cd
cd RootFolder
touch root.txt
ls -ltr / > root.txt
cd
date
sleep 3
mkdir ~/HomeFolder
date
sleep 3
cd
cd HomeFolder
touch home.txt
ls -ltr ~> home.txt
date 
sleep 3
cat ~/RootFolder/root.txt
cat ~/HomeFolder/home.txt
