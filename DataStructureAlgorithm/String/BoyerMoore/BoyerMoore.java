public class BoyerMoore{
    public static void main(String args[]) {
        int p = BoyerMooreFunc("ababcdefghabcxdezcabacabac", "abac");//26
        System.out.print("find String position: " + p);
    }
    static int BoyerMooreFunc(String target, String p){
        int pt, pp;
        int targetlen = target.length();
        int plen = p.length();
        System.out.printf("targetlen: %d, plen: %d\n", targetlen, plen);
        
        int[] check = new int[Character.MAX_VALUE + 1];
        for(pt=0; pt<plen-1; ++pt)
            check[p.charAt(pt)] = plen-pt-1;
        
        System.out.print("check table: ");
        for(int i=0; i<100; i++){
            System.out.print(check[i]+" ");
        }

        System.out.printf("\npt: %d\n", pt);
        while(pt<targetlen){
            pp = plen-1;
            while(target.charAt(pt)==p.charAt(pp)){
                if(pp==0) return pt;
                --pp;
                --pt;
            }
            pt += (check[target.charAt(pt)] > plen-pp) ? check[target.charAt(pt)] : plen-pp;
        }
        return -1;
    }
}