function solution(n, lost, reserve) {
  let ans = 0;
  const arr = new Array(n + 1).fill(1);
  lost.forEach((element) => {
    arr[element]--;
  });
  reserve.forEach((element) => {
    arr[element]++;
  });
  for (let i = 1; i < arr.length; ++i) {
    if (arr[i] === 2) {
      if (i > 1 && arr[i - 1] === 0) {
        arr[i]--;
        arr[i - 1]++;
      } else if (i < arr.length - 1 && arr[i + 1] === 0) {
        arr[i]--;
        arr[i + 1]++;
      }
    }
  }
  for (let i = 1; i < arr.length; ++i) {
    if (arr[i] >= 1) ans++;
  }
  return ans;
}
solution(5, [2, 4], [1, 3, 5]);
