function findsum(n) {
  var answer = 0;
  //n=123
  while (n !== 0) {
    answer += n % 10; //3
    n /= 10; //12
    n = Math.floor(n);
  }
  return answer;
}

function solution(x) {
  let sum = findsum(x);
  if(x%sum===0) return true;
  else return false;
  return answer;
}
