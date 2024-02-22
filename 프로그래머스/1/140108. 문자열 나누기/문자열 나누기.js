function solution(s) {
  let arr = [...s];
  let a = 0;
  let b = 0;
  let standard = "";
  let result = 0;
  for (let i = 0; i < arr.length; ++i) {
    if (a == 0) {
      standard = arr[i];
      a++;
    } else {
      if (standard === arr[i]) a++;
      else b++;
    }
    if (i === arr.length - 1) {
      result++;
      break;
    }
    if (a === b) {
      result++;
      a = 0;
      b = 0;
    }
  }
  return result;
}
s = "abracadabra";
console.log(solution(s));
