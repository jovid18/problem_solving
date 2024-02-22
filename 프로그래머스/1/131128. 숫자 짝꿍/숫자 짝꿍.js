function solution(X, Y) {
  let array1 = [...X];
  let array2 = [...Y];
  let ans = "";
  for (let i = 0; i <= 9; ++i) {
    let str = String(i);
    let cnt1 = array1.reduce((accumulator, currentValue) => {
      return currentValue === str ? accumulator + 1 : accumulator;
    }, 0);
    let cnt2 = array2.reduce((accumulator, currentValue) => {
      return currentValue === str ? accumulator + 1 : accumulator;
    }, 0);
    for (let j = 0; j < Math.min(cnt1, cnt2); ++j) {
      ans = str + ans;
    }
  }
  if (ans === "") return "-1";
  else if (Number(ans) === 0) return "0";
  else return ans;
}
