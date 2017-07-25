#include <string>
#include <iostream>
#include <sstream>
#include <vector>

std::vector<std::string> getNextLineAndSplitIntoTokens(std::istringstream& str)
{
    std::vector<std::string>   result;
    std::string                line;
    std::getline(str,line);

    std::stringstream          lineStream(line);
    std::string                cell;

    while(std::getline(lineStream,cell, ','))
    {
        result.push_back(cell);
    }
    // This checks for a trailing comma with no data after it.
    if (!lineStream && cell.empty())
    {
        // If there was a trailing comma then add an empty element.
        result.push_back("");
    }
    return result;
}

std::vector<int> splitTokensIntoChannels(std::vector<std::string> str)
{
    std::vector<int> channels;
    std::vector<int> temp;
    std::string token = "-";
    bool hasToken = false;

  for(int i = 0; i<str.size(); i++)
  {
      int tokenPosition = 0;
      for(int j = 0; j<str[i].length(); j++)
      {
        if(str[i].compare(j,1,token) == 0)
        {
          hasToken = true;
          tokenPosition = j;
        }
      }

      if(hasToken == true)
      {
        int first = 0, second = 0;
        std::string temp;
        first = std::stoi(str[i]);
        
        for(int j = tokenPosition+1; j < str[i].length();j++)
          temp += str[i].at(j);
        second = std::stoi(temp);
        for(int i = first-1; i <= second-1; i++)
          channels.push_back(i);
      }
      else
        channels.push_back(std::stoi(str[i])-1);
      hasToken = false;
  }

	return channels;
}

int main()
{	
	//std::string str = "1-4,5,6,16";
	std::istringstream isr("1-4,7-9,12,16");
	std::vector<std::string> ret = getNextLineAndSplitIntoTokens(isr);
	// copy by value
	for (auto i = ret.begin(); i != ret.end(); ++i)
		std::cout << *i << "\n";
	std::cout << "\n";
	//reference
	for (auto& i:ret)
		std::cout << i << "\n";
	std::vector<int> channels = splitTokensIntoChannels(ret);
	for (auto&i:channels)
		std::cout << i << "\n";
	return 0;
}

