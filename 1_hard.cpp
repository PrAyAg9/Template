// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >>n;
//     while(n>0){
//         int m,a,b,c;
//         int count = 0;
//         cin >> m>>a>>b>>c;
//         if(m>a&&m>b){
//             if(a+c>m && b+c>m){
//                 cout << 2*m <<endl;
//             }
//             else if(a+c<m && b+c>m){
//                 c = c-(m-b);
//                 cout << m+a+c<<endl;
//             }
//             else if(a+c>m && b+c<m){
//                 c = c-(m-a);
//                 if(c>=0){
//                     cout << m+b+c
//                 }else{
                    
//                 }
                
//             }
//             else{
//                 cout << a+b+c<<endl;
//             }
//         }
//         else if(m>a&&m<b){
//             if(a+c>=m){
//                 cout << 2*m <<endl;
//             }
//             else{
//                 cout << m + a+c<<endl;
//             }
//         }
//         else if(m<a && m>b){
//             if(b+c>=m){
//                 cout << 2*m <<endl;
//             }
//             else{
//                 cout << m + b+c<<endl;
//             }
//         }
//         else{
//             cout << 2*m<<endl;
//         }
//         n--;

//     }
// }

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t; 
    cin >> t;

    while (t--) {
        long long m, a, b, c;
        cin >> m >> a >> b >> c;

        long long row1 = min(a, m);
        long long row2 = min(b, m);

        long long remaining_seats = 2 * m - row1 - row2;

        long long no_preference = min(c, remaining_seats);

        long long max_seated = row1 + row2 + no_preference;
        cout << max_seated << endl;
    }

    return 0;
}
