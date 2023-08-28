
import java.util.*;

class isunique{
    // stirng has all unique character

   static boolean  isUnique(String str,int n){
    HashMap<Character,Integer> mp=new HashMap<>();
    for(int i=0;i<n;i++){
        if(mp.containsKey(str.charAt(i))){
            return false;
        }
        else{
            mp.put(str.charAt(i),1);
        }
    }
    return true;


    //toCharArray() - convert string to string array


    // for(char ch: str.toCharArray())
    // {
    // 	if(mp.containsKey(ch))
    // 	{
    //         mp.put(ch,mp.get(ch)+1);
    // 		return false;
    // 	}
    // 	else 
    // 		mp.put(ch,1);
    // }
    // return true;

    
    }
    public static void main(String args[]){
            String str = "riteshismyname";
            int n = str.length();
            boolean ans = isUnique(str,n);
            System.out.print(ans);
    }
}