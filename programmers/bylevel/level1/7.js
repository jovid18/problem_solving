function solution(n) {
  let ans = [];
  let a = String(n).split('').reverse();
  for (let i = 0; i < a.length; i++) {
    ans.push(Number(a[i]));
  }
  return ans;
}

let n = 12345;
solution(n);

//n을 10으로 나눠서 하는 방법도  좋을것 같다.
//reduce 방식도 고려
