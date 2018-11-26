dir=$(pwd)

sed -i "/alias quadsolve/d" ~/.bashrc 2> /dev/null /dev/null
unalias quadsolve 2> /dev/null > /dev/null
echo "\nalias quadsolve='cd $(pwd) && make runv3 && cd $(pwd)'\n" >> ~/.bashrc

echo "\n------------------------------------------------------------------\n"
echo "\nProgram Installation Complete!"
echo "\nPlease reload bash with 'source ~/.bashrc'"
echo "Then use the command 'quadsolve' to run the program!"
echo "\n------------------------------------------------------------------\n"
echo "\n"
