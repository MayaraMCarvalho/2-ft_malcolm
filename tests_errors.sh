#!/bin/bash

export LC_NUMERIC="C"

# Colors
red='[31;1m'
blue='[36;1m'
green='[32;1m'
yellow='[33;1m'
purple='[35;1m'
gray='[37;1m'
reset='[0m'

# Caminho para o executável do seu programa em C
PROGRAM="./ft_malcolm"

comp="make re && clear"

$comp
clear

# Create Test folder
mkdir -p Test

# Create Test files_______________________________________________________________

echo -e "${blue}\n---------------------------------------------------------------------------"
echo "----------------------------- FT_MALCOLM TEST -----------------------------"
echo "---------------------------------------------------------------------------"
echo "Creating test files..."
echo "---------------------------------------------------------------------------"
echo "empty.result..."
echo "ip_error1.result..."
echo "ip_error2.result..."
echo "mac_error1.result..."
echo "mac_error2.result..."
echo "mac_error3.result..."
echo "---------------------------------------------------------------------------"

echo "${red}Error: insufficient argument number!

Usage: ft_malcolm <Source IP> <Source MAC Address> <Target IP> <Target MAC Address> [Flag]: optional${reset}
" > ./Test/empty.result

echo -ne "${red}ft_malcolm: unknown host or invalid IP address (10.11.1991.111)\n${reset}" > ./Test/ip_error1.result
echo -ne "${red}ft_malcolm: unknown host or invalid IP address (10.11.11.1181)\n${reset}" > ./Test/ip_error2.result

echo -ne "${red}ft_malcolm: invalid mac address (aa:bb:cc:dd:eee:ff)\n${reset}" > ./Test/mac_error1.result
echo -ne "${red}ft_malcolm: invalid mac address (aaa:bb:cc:dd:ee:ff)\n${reset}" > ./Test/mac_error2.result
echo -ne "${red}ft_malcolm: invalid mac address (1Z:12:34:56:78:90)\n${reset}" > ./Test/mac_error3.result

# Initialize counters
total_tests=0
successful_tests=0

# Initialize test number
test_number=0

# Run tests_______________________________________________________________________

echo -e "${blue}\n---------------------------------------------------------------------------"
echo "Running tests..."
echo "---------------------------------------------------------------------------"

# Test 1
((total_tests++))
echo -e "${blue}\n---------------------------------------------------------------------------"
echo -e "${blue}--------------------------------- Test 1 ----------------------------------"
echo "Test for empty parameters..."
echo "---------------------------------------------------------------------------"
echo -en "${gray}"
echo "${PROGRAM}"
echo -e "${blue}\n---------------------------------------------------------------------------"
echo -e "${purple}Output expected: "
cat ./Test/empty.result
echo -e "${yellow}Output result: "
${PROGRAM} "" > ./Test/empty.output
${PROGRAM}
echo -e "${blue}---------------------------------------------------------------------------"
if [ $? -eq 0 ]; then
	diff_output=$(diff Test/empty.result Test/empty.output)
	if [ -z "$diff_output" ]; then
		echo -e "${green}✅ Passed${reset}"
		((successful_tests++))
	else
		echo -e "${red}❌ Failed${reset}"
	fi
fi
echo -e "${blue}---------------------------------------------------------------------------"

# Test 2
((total_tests++))
echo -e "${blue}\n---------------------------------------------------------------------------"
echo -e "${blue}--------------------------------- Test 2 ----------------------------------"
echo "Test for parameters with erros..."
echo "---------------------------------------------------------------------------"
echo -en "${gray}"
echo "${PROGRAM} 10.11.11.11 aa:bb:cc:dd:ee:ff 10.11.1991.111 aa:bb:cc:dd:ee:ff"
echo -e "${blue}\n---------------------------------------------------------------------------"
echo -e "${purple}Output expected: "
cat ./Test/ip_error1.result
echo -e "${yellow}\nOutput result: "
${PROGRAM} "10.11.11.11" "aa:bb:cc:dd:ee:ff" "10.11.1991.111" "aa:bb:cc:dd:ee:ff" > ./Test/ip_error1.output
${PROGRAM} "10.11.11.11" "aa:bb:cc:dd:ee:ff" "10.11.1991.111" "aa:bb:cc:dd:ee:ff"
echo -e "${blue}\n---------------------------------------------------------------------------"
if [ $? -eq 0 ]; then
	diff_output=$(diff Test/ip_error1.result Test/ip_error1.output)
	if [ -z "$diff_output" ]; then
		echo -e "${green}✅ Passed${reset}"
		((successful_tests++))
	else
		echo -e "${red}❌ Failed${reset}"
	fi
fi
echo -e "${blue}---------------------------------------------------------------------------"

# Test 3
((total_tests++))
echo -e "${blue}\n---------------------------------------------------------------------------"
echo -e "${blue}--------------------------------- Test 3 ----------------------------------"
echo "Test for parameters with erros..."
echo "---------------------------------------------------------------------------"
echo -en "${gray}"
echo "${PROGRAM} 10.11.11.1181 aa:bb:cc:dd:ee:ff 10.11.11.111 aa:bb:cc:dd:ee:ff"
echo -e "${blue}\n---------------------------------------------------------------------------"
echo -e "${purple}Output expected: "
cat ./Test/ip_error2.result
echo -e "${yellow}\nOutput result: "
${PROGRAM} "10.11.11.1181" "aa:bb:cc:dd:ee:ff" "10.11.11.111" "aa:bb:cc:dd:ee:ff" > ./Test/ip_error2.output
${PROGRAM} "10.11.11.1181" "aa:bb:cc:dd:ee:ff" "10.11.11.111" "aa:bb:cc:dd:ee:ff"
echo -e "${blue}\n---------------------------------------------------------------------------"
if [ $? -eq 0 ]; then
	diff_output=$(diff Test/ip_error2.result Test/ip_error2.output)
	if [ -z "$diff_output" ]; then
		echo -e "${green}✅ Passed${reset}"
		((successful_tests++))
	else
		echo -e "${red}❌ Failed${reset}"
	fi
fi
echo -e "${blue}---------------------------------------------------------------------------"

# Test 4
((total_tests++))
echo -e "${blue}\n---------------------------------------------------------------------------"
echo -e "${blue}--------------------------------- Test 4 ----------------------------------"
echo "Test for parameters with erros..."
echo "---------------------------------------------------------------------------"
echo -en "${gray}"
echo "${PROGRAM} 10.11.11.11 aa:bb:cc:dd:ee:ff 10.11.11.111 aa:bb:cc:dd:eee:ff"
echo -e "${blue}\n---------------------------------------------------------------------------"
echo -e "${purple}Output expected: "
cat ./Test/mac_error1.result
echo -e "${yellow}\nOutput result: "
${PROGRAM} "10.11.11.11" "aa:bb:cc:dd:ee:ff" "10.11.11.111" "aa:bb:cc:dd:eee:ff" > ./Test/mac_error1.output
${PROGRAM} "10.11.11.11" "aa:bb:cc:dd:ee:ff" "10.11.11.111" "aa:bb:cc:dd:eee:ff"
echo -e "${blue}\n---------------------------------------------------------------------------"
if [ $? -eq 0 ]; then
	diff_output=$(diff Test/mac_error1.result Test/mac_error1.output)
	if [ -z "$diff_output" ]; then
		echo -e "${green}✅ Passed${reset}"
		((successful_tests++))
	else
		echo -e "${red}❌ Failed${reset}"
	fi
fi
echo -e "${blue}---------------------------------------------------------------------------"

# Test 5
((total_tests++))
echo -e "${blue}\n---------------------------------------------------------------------------"
echo -e "${blue}--------------------------------- Test 5 ----------------------------------"
echo "Test for parameters with erros..."
echo "---------------------------------------------------------------------------"
echo -en "${gray}"
echo "${PROGRAM} 10.11.11.11 aaa:bb:cc:dd:ee:ff 10.11.11.111 aa:bb:cc:dd:ee:ff"
echo -e "${blue}\n---------------------------------------------------------------------------"
echo -e "${purple}Output expected: "
cat ./Test/mac_error2.result
echo -e "${yellow}\nOutput result: "
${PROGRAM} "10.11.11.11" "aaa:bb:cc:dd:ee:ff" "10.11.11.111" "aa:bb:cc:dd:ee:ff" > ./Test/mac_error2.output
${PROGRAM} "10.11.11.11" "aaa:bb:cc:dd:ee:ff" "10.11.11.111" "aa:bb:cc:dd:ee:ff"
echo -e "${blue}\n---------------------------------------------------------------------------"
if [ $? -eq 0 ]; then
	diff_output=$(diff Test/mac_error2.result Test/mac_error2.output)
	if [ -z "$diff_output" ]; then
		echo -e "${green}✅ Passed${reset}"
		((successful_tests++))
	else
		echo -e "${red}❌ Failed${reset}"
	fi
fi
echo -e "${blue}---------------------------------------------------------------------------"

# Test 6
((total_tests++))
echo -e "${blue}\n---------------------------------------------------------------------------"
echo -e "${blue}--------------------------------- Test 6 ----------------------------------"
echo "Test for parameters with erros..."
echo "---------------------------------------------------------------------------"
echo -en "${gray}"
echo "${PROGRAM} 10.11.11.11 1Z:12:34:56:78:90 10.11.11.111 aa:bb:cc:dd:ee:ff"
echo -e "${blue}\n---------------------------------------------------------------------------"
echo -e "${purple}Output expected: "
cat ./Test/mac_error3.result
echo -e "${yellow}\nOutput result: "
${PROGRAM} "10.11.11.11" "1Z:12:34:56:78:90" "10.11.11.111" "aa:bb:cc:dd:ee:ff" > ./Test/mac_error3.output
${PROGRAM} "10.11.11.11" "1Z:12:34:56:78:90" "10.11.11.111" "aa:bb:cc:dd:ee:ff"
echo -e "${blue}\n---------------------------------------------------------------------------"
if [ $? -eq 0 ]; then
	diff_output=$(diff Test/mac_error3.result Test/mac_error3.output)
	if [ -z "$diff_output" ]; then
		echo -e "${green}✅ Passed${reset}"
		((successful_tests++))
	else
		echo -e "${red}❌ Failed${reset}"
	fi
fi
echo -e "${blue}---------------------------------------------------------------------------"

echo -e "${blue}\n---------------------------------------------------------------------------"
echo "Tests finished..."
echo -e "---------------------------------------------------------------------------${reset}"

# Calculate percentage of hits
percentage=$(echo "scale=4; $successful_tests / $total_tests * 100" | bc)

# Print results with color
echo -en "\n\e[33mTotal number of tests performed: \e[94m$total_tests"
echo -en "\n\e[33mTests OK: \e[94m$successful_tests"
echo -e "\n\e[33mPercentage of hits: \e[94m$(printf "%.2f" "$percentage")%\n"

if [ "$(printf "%.2f" "$percentage")" = "100.00" ]; then
	echo -e "${green}------------------------- 𝙲𝚘𝚗𝚐𝚛𝚊𝚝𝚞𝚕𝚊𝚝𝚒𝚘𝚗𝚜!!!🎉🎊 --------------------------\n"
else
	echo -e "${red}-------------------------- 𝚄𝚗𝚏𝚘𝚛𝚝𝚞𝚗𝚊𝚝𝚎𝚕𝚢!!!⛔😩 ---------------------------\n"
fi


