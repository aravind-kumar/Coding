
import java.util.*;

class KthFrequenceInMArrays {

public static List<Integer> doIntersection(List<Integer> set1,List<Integer> set2) {
    
   Set<Integer> intersection = new HashSet<>();
 
   intersection.addAll(set1);
   for(int num : set2) {
      if(!intersection.contains(num)) {
          intersection.remove((Integer)num); 
      }
   }
   List<Integer> ans = new ArrayList<>();
   ans.addAll(intersection);
   return ans;
}


public static List<Integer> doIntersection(List<List<Integer>> inputArray) {
   
    if(!inputArray.isEmpty()) {
        List<Integer> commonElements = new ArrayList<>();
         
        commonElements.addAll(inputArray.get(0));   
 
        for(int i=1;i<inputArray.size()-1;++i) {
            commonElements=doIntersection(commonElements,inputArray.get(i));
        }
        return commonElements;
     } 
     return null;
}


public static Integer getKthElement(List<Integer> listElements,int k) {
   Collections.sort(listElements);
   System.out.println(listElements);
   return listElements.get(k);
    

}



public static Integer getKthCommonElement(List<List<Integer>> inputArray,int k) {
   List<Integer> commonElements = doIntersection(inputArray);
   if(k<commonElements.size()) { 
       return getKthElement(commonElements,k);
   }
   return null;
}


public static void main(String[] args) {
  
   Scanner in = new Scanner(System.in);
   System.out.println("Enter the number of arrays");
   int numOfArrays = in.nextInt();
   List<List<Integer>> inputArrays = new ArrayList<List<Integer>>();
   System.out.println("Enter the number of elements to be inserted");
   int m=in.nextInt();
   for(int i=0;i<numOfArrays;++i) {
       List<Integer> arrList = new ArrayList<>();
       System.out.println("Enter the elements of the array");
       for (int j=0;j<m;++j) {
           System.out.println("Enter the element");
           arrList.add(in.nextInt());
       }
       inputArrays.add(arrList);
   }
   System.out.println("Enter the kth element to be retrived"); 
   int k = in.nextInt();
   int ans = getKthCommonElement(inputArrays,k);
   System.out.println("The ans is " + ans);

}

}
