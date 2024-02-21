function solution(n) {
  var answer = 0;
  let str = String(n);
  let strarr = [...str];
  strarr.map(Number);
  strarr.sort((a, b) => {
    return b - a;
  });
  for (let i = 0; i < strarr.length; ++i) {
    answer += strarr[i] * Math.pow(10, strarr.length - i - 1);
  }
  return answer;
}
//array.join 사용

let n = 118372;
console.log(solution(n));






