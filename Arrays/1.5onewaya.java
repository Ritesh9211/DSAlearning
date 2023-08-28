import java.util.HashMap;

class oneaway {

    static boolean solve(String s1,String s2){
        int n=s1.length();
        int m=s2.length()-n;
        if(Math.abs(m)>1) return false;
        HashMap<Character,Integer>mp = new HashMap<>();
        int flag=0;
        for(Character ch:s1.toCharArray()){
            if(mp.containsKey(ch)){
                mp.put(ch,mp.get(ch)+1);
            }
            else{
                mp.put(ch,1);
            }
        }

        for(Character ch: s2.toCharArray()){
            if(mp.containsKey(ch)){
              mp.put(ch,mp.get(ch)-1);
              if(mp.get(ch)==0) mp.remove(ch);
            }
        }
        if(mp.size()>1) return false;
        return true;
    }
    public static void main(String[] args) {
        String s1="pale";
        String s2="ake";
        System.out.println(solve(s1,s2));
    }
}
