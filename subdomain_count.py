class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        hmap = {}
        for domains in cpdomains:
            vals = domains.split()
            count = int(vals[0])
            complete = "".join(vals[1:])
            
            if complete not in hmap:
                hmap[complete] = count
            else:
                hmap[complete]+=count
                
            domains = "".join(vals[1:]).split('.')[1:]
            website = domains[len(domains)-1]
            if website not in hmap:
                hmap[website] = count
            else:
                hmap[website]+=count
                
            for domain in domains:
                if domain == website:
                    continue
                domain+="."+website
                if domain not in hmap:
                    hmap[domain] = count
                else:
                    hmap[domain]+=count
            
        ans = []
        for k,v in hmap.items():
            ans.append(str(v) + " " + k)
        
        return ans
                
        
