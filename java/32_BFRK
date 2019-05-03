public static int bF(String a,String b) {
		int m=a.length(),n=b.length(),k;
		char[] a1=a.toCharArray();
		char[] b1=b.toCharArray();
		for(int i=0;i<=m-n;i++) {
			k=0;
			for(int j=0;j<n;j++) {
				if(a1[i+j]==b1[j]) {
					k++;
				}
				else
					break;
			}
			if(k==n) {
				return i;
			}
		}
		return -1;
	}
public static int rK(String a,String b) {
		int m=a.length(),n=b.length(),s,j;
		int[] hash=new int[m-n+1];
		int[] table=new int[26];
		char[] a1=a.toCharArray();
		char[] b1=b.toCharArray();
		s=1;
		//将26的次方存储在一个表里，取的时候直接用,虽然溢出，但没啥问题
		for(j=0;j<26;j++) {
			table[j]=s;
			s*=26;
		}
		for(int i=0;i<=m-n;i++) {
			s=0;
			for(j=0;j<n;j++) {
				s+=(a1[i+j]-'a')*table[n-1-j];
			}
			hash[i]=s;
		}
		s=0;
		for(j=0;j<n;j++) {
			s+=(b1[j]-'a')*table[n-1-j];
		}
		for(j=0;j<m-n+1;j++) {
			if(hash[j]==s) {
				return j;
			}
		}
		return -1;
	}
