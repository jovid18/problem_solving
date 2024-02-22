function solution(arr1, arr2) {
  // 행렬의 덧셈
  let answer = [];
  for (let i = 0; i < arr1.length; i++) {
    //answer에 넣을 배열(nowarr)을 만들자
    let nowarr = [];
    for (let j = 0; j < arr1[0].length; j++) {
      //nowarr에 원소 추가
      nowarr.push(arr1[i][j] + arr2[i][j]);
    }
    //만든 nowarray를 answer에 추가
    answer.push(nowarr);
  }
  return answer;
}