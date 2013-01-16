//@file BSTHTMLParser.cpp
//@author Colin Knappert
//@date 11/19/2012

//@input % WordFrequency input_file_name min_freq_num [ignore_file_name


#include "BinarySearchTree.cpp"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;


int g_count;
BinarySearchTree g_one;
BinarySearchTree g_two;
BinarySearchTree g_three;
BinarySearchTree g_four;
BinarySearchTree g_five;
BinarySearchTree g_six;
BinarySearchTree g_seven;
BinarySearchTree g_eight;


void SearchField(string search)
{

    string delimiters = " <>""/\n,._:=!?";
    string limiters = " \f\n\r\t\v";
    int current = 0;
    int next = 0;
    string SearchList[10];
    while(next != string::npos)
    {
        current = next + 1;
        next = search.find_first_of(delimiters, current);
        search.erase(current, search.find_first_not_of(limiters));
        
        SearchList[current] = search.substr( current, next - current );
    }

     
     
     
    
     
             
}
void ProcessQueries(string htmls[], string badwords[])
{
     BinarySearchTree WikiHTML;
     BinarySearchTree WikiWebBrowser;
     BinarySearchTree WikiWebPage;
     BinarySearchTree WikiInternet;
     BinarySearchTree WikiWebServer;
     BinarySearchTree WikiWebsite;
     BinarySearchTree WikiApplicationSoftware;
     BinarySearchTree WikiHTTP;
     WikiHTML.WordFrequency("WikipediaHTML.html", 1, badwords); 
     WikiWebBrowser.WordFrequency("WikipediaWebBrowser.html", 1, badwords);
     WikiWebPage.WordFrequency("WikipediaWebPage.html", 1, badwords);
     WikiInternet.WordFrequency("WikipediaInternet.html", 1, badwords);
     WikiWebServer.WordFrequency("WikipediaWebServer.html", 1, badwords);
     WikiWebsite.WordFrequency("WIkipediaWebsite.html", 1, badwords);
     WikiApplicationSoftware.WordFrequency("WikpediaApplicationSoftware.html", 1, badwords);
     WikiHTTP.WordFrequency("WikpediaHypertextTransferProtocol.html", 1, badwords);        
     string search;
    
     while(search != "-1")
     {
         int HTML = 0;
         int WebBrowser = 0;
         int WebPage = 0;
         int Internet = 0;
         int WebServer = 0;
         int Website = 0;
         int ApplicationSoftware = 0;
         int HTTP = 0;
         cout << "\nMenu\n";
         cout << "Enter a query or -1 to quit.\n";
         //getline(cin, search);
         cin >> search;
         cout << search;
         string delimiters = " ";
         string SearchList[10];
         string word;
         int startpos=0;
         int endpos=0;
         int x =0;
         endpos = search.find_first_of(delimiters, startpos);
         //cout << endpos;
         if(search.find_first_of(delimiters, startpos)< 0)
         {
             while (endpos != -1)
             {       
                 // Split input string into words
                 startpos = endpos+1; //jump past sep
                 endpos = search.find_first_of(delimiters, startpos); // find next
                 word = search.substr( startpos, endpos - startpos );
                 //SearchList[x] = word;
                 x++;
                 
                 // Increase counts when word is found
                 
             }
             for (int x = 0; x < 10; x++)
             {
                 cout << SearchList[x];
             }
             HTML = HTML + WikiHTML.count(word);
             WebBrowser = WebBrowser + WikiWebBrowser.count(word);
             WebPage = WebPage + WikiWebPage.count(word);
             Internet = Internet + WikiInternet.count(word);
             WebServer = WebServer + WikiWebServer.count(word);
             Website = Website + WikiWebsite.count(word);
             ApplicationSoftware = ApplicationSoftware + WikiApplicationSoftware.count(word);
             HTTP = HTTP + WikiHTTP.count(word);
         }

         HTML = HTML + WikiHTML.count(search);
         WebBrowser = WebBrowser + WikiWebBrowser.count(search);
         WebPage = WebPage + WikiWebPage.count(search);
         Internet = Internet + WikiInternet.count(search);
         WebServer = WebServer + WikiWebServer.count(search);
         Website = Website + WikiWebsite.count(search);
         ApplicationSoftware = ApplicationSoftware + WikiApplicationSoftware.count(search);
         HTTP = HTTP + WikiHTTP.count(search);
         
         system("CLS");
         
         // Enter values into array
         int SearchValues[8];
         SearchValues[0] = HTML;
         SearchValues[1] = WebBrowser;
         SearchValues[2] = WebPage;
         SearchValues[3] = Internet;
         SearchValues[4] = WebServer;
         SearchValues[5] = Website;
         SearchValues[6] = ApplicationSoftware;
         SearchValues[7] = HTTP;
         
         // Sort array
         int i, j;
         int temp;   // holding variable
         int numLength = 8; 
         for (i=0; i< (numLength -1); i++)    // element to be compared
        {
              for(j = (i+1); j < numLength; j++)   // rest of the elements
             {
                    if (SearchValues[i] < SearchValues[j])          // descending order
                   {
                            temp= SearchValues[i];          // swap
                            SearchValues[i] = SearchValues[j];
                            SearchValues[j] = temp;
                   }
              }
         }
         
         // Menu print out
         // Prints priority by matching values
         // Equal priorities make a tie
         cout << "Results:" << search << "\n";
         cout << "_______________________________" << "\n";
         cout << "WikiHTML: " << HTML;
         if(HTML == 0);
         else if(SearchValues[0] == HTML) cout << "(Priority = Z)";
         else if(SearchValues[1] == HTML) cout << "(Priority = Y)";
         else if(SearchValues[2] == HTML) cout << "(Priority = X)";
         else if(SearchValues[3] == HTML) cout << "(Priority = W)";
         cout << "\n" << "WikiWebBrowser: " << WebBrowser;
         if(HTML == 0);
         else if(SearchValues[0] == WebBrowser) cout << "(Priority = Z)";
         else if(SearchValues[1] == WebBrowser) cout << "(Priority = Y)";
         else if(SearchValues[2] == WebBrowser) cout << "(Priority = X)";
         else if(SearchValues[3] == WebBrowser) cout << "(Priority = W)";
         cout << "\n" << "WikiWebPage: " << WebPage;
         if(WebPage == 0);
         else if(SearchValues[0] == WebPage) cout << "(Priority = Z)";
         else if(SearchValues[1] == WebPage) cout << "(Priority = Y)";
         else if(SearchValues[2] == WebPage) cout << "(Priority = X)";
         else if(SearchValues[3] == WebPage) cout << "(Priority = W)";
         cout << "\n" << "WikiInternet: " << Internet;
         if(Internet == 0);
         else if(SearchValues[0] == Internet) cout << "(Priority = Z)";
         else if(SearchValues[1] == Internet) cout << "(Priority = Y)";
         else if(SearchValues[2] == Internet) cout << "(Priority = X)";
         else if(SearchValues[3] == Internet) cout << "(Priority = W)";
         
         cout << "\n" << "WikiWebServer: " << WebServer;
         if(WebServer == 0);
         else if(SearchValues[0] == WebServer) cout << "(Priority = Z)";
         else if(SearchValues[1] == WebServer) cout << "(Priority = Y)";
         else if(SearchValues[2] == WebServer) cout << "(Priority = X)";
         else if(SearchValues[3] == WebServer) cout << "(Priority = W)";
         
         cout << "\n" << "WikiWebsite: " << Website;
         if(Website == 0);
         else if(SearchValues[0] == Website) cout << "(Priority = Z)";
         else if(SearchValues[1] == Website) cout << "(Priority = Y)";
         else if(SearchValues[2] == Website) cout << "(Priority = X)";
         else if(SearchValues[3] == Website) cout << "(Priority = W)";
         
         cout << "\n" << "WikiApplicationSoftware: " << ApplicationSoftware;
         if(ApplicationSoftware == 0);
         else if(SearchValues[0] == ApplicationSoftware) cout << "(Priority = Z)";
         else if(SearchValues[1] == ApplicationSoftware) cout << "(Priority = Y)";
         else if(SearchValues[2] == ApplicationSoftware) cout << "(Priority = X)";
         else if(SearchValues[3] == ApplicationSoftware) cout << "(Priority = W)";
         
         cout << "\n" << "WikiHTTP: " << HTTP;
         if(HTTP == 0);
         else if(SearchValues[0] == HTTP) cout << "(Priority = Z)";
         else if(SearchValues[1] == HTTP) cout << "(Priority = Y)";
         else if(SearchValues[2] == HTTP) cout << "(Priority = X)";
         else if(SearchValues[3] == HTTP) cout << "(Priority = W)" << "\n";
         cout << "\n" << "-------------------------------";
     }
}


     

int main()
{
     string badwords[2] = {"the", "more"};
     string htmls[8] = {"WikipediaHTML.html", "WikipediaWebBrowser.html", "WikipediaWebPage.html", "WikipediaInternet.html", "WikipediaWebServer.html", "WikipediaWebsite.html", "WikipediaApplicationSoftware.html", "WikipediaHypertextTranfserProtocol.html"};        
     string search;
     ProcessQueries(htmls, badwords);
     cin.get();
     return 0;
}
