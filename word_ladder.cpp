int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int count = 1;
        queue<string> adjList;
        getNextDestinations(beginWord,wordList,adjList);
        ++count;
        while(!adjList.empty()) {    
            int numOfDestinations = adjList.size();
            for(int i=0;i<numOfDestinations;++i) {
                string nextDestination = adjList.front();
                adjList.pop();
                if(nextDestination.compare(endWord) == 0)
                    return count;
                getNextDestinations(nextDestination,wordList,adjList);
            }
            ++count;   
        }
        return 0;
    }
    
    void getNextDestinations(string source,vector<string>& wordList,queue<string>& output)
    {
        remove_if(wordList.begin(),wordList.end(),
                [source](string input) { return source.compare(input)==0;});
        for(int i=0;i<source.length();++i){
            char old=source[i];
            for(int j=0;j<26;++j) {
                source[i] = 'a' + j;
                auto it = find(wordList.begin(),wordList.end(),source);
                if(it != wordList.end())
                {
                    wordList.erase(it);
                    output.push(source);
                }
            }
            source[i]=old;
        }
        
    }
