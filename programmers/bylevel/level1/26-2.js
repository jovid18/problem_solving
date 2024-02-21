function solution(s) {
  if (s.length !== 4 && s.length !== 6) return false;
  let arr = s.split('');
  for (let i = 0; i < arr.length; i++) {
    //arr[i]가 아스키코드상 0보다 작거나 9보다 크면 숫자로 이루어지지 않은 것이므로 false return;
    if (arr[i] < '0' || '9' < arr[i]) {
      //if (!Number(arr[i])) {    // 숫자가 0이면 false로 된다
      return false;
    }
  }
  return true;
}

//Number(s)!==0 일때도 확인
