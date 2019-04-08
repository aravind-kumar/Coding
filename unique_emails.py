class Solution:
    
    def numUniqueEmails(self, emails: List[str]) -> int:
        hmap=set()
        def getLocalName(inputString) :
            localName = inputString.split('@')[0]
            localName = localName.split('+')[0]
            localName = localName.replace('.','')
            return localName
        
        def getDomainName(inputString) :
            domainName = inputString.split('@')[1]
            return domainName
        
        for email in emails:
            localName = getLocalName(email)
            domailName = getDomainName(email)
            hmap.add(localName + '@' + domailName)
        return len(hmap)
