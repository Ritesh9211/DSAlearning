import java.util.HashMap;

public class checkpermutation {

    static boolean ispermutation(String s1,String s2){

        if(s1.length()!=s2.length()) return false;
        HashMap<Character,Integer> mp = new HashMap<>();

        for(Character ch: s1.toCharArray()){
            if(mp.containsKey(ch)){
                mp.put(ch,mp.get(ch)+1);
            }
            else{
                mp.put(ch,1);
            }
        }
        for(Character ch:s2.toCharArray()){
            if(mp.containsKey(ch) && mp.get(ch)!=0){
                mp.put(ch,mp.get(ch)-1);
            }
            else{
                return false;
            }
        }
        


        return true;
    }
    public static void main(String args[]){
        //given two string write a method to check if one is permutation of other
        String s1 = "abcd";
        String s2 = "bbdc";
        System.out.println(ispermutation(s1,s2));
        
    }
}


/*
 map all functions
 mp.remove(key);
 mp.putIfAbsent(key, value);  
 mp.replace(key,value); works only if key already present
 mp.puAll(anothermap);

 */