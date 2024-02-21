// 우정 : 3차원 배열 시도한 흔적...너무 어렵다 ㅠ

function solution(arr1, arr2) {
  // answer 배열 선언
  let answer = [];
  for (let i = 0; i < arr1.length; i++) {
    //answer에 넣을 배열 nowarr 선언
    let nowarr1 = [];
    for (let j = 0; j < arr1[0].length; j++) {
      //[4,6],[7,9]
      //nowarr에 원소 추가
      let nowarr2 = [];
      for (let k = 0; k < arr1[0][0].length; k++) {
        nowarr2.push(arr1[i][j][k] + arr2[i][j][k]);
      }
      nowarr1.push(nowarr2);
    }
    //만든 nowarray를 answer에 추가
    answer.push(nowarr1);
  }
  return answer;
}

let arr1 = [
  [
    [1, 2],
    [3, 4],
  ],
  [
    [4, 2],
    [3, 4],
  ],
];
let arr2 = [
  [
    [1, 2],
    [3, 4],
  ],
  [
    [4, 2],
    [3, 4],
  ],
];
console.table(arr1);
console.table(arr2);
console.table(solution(arr1, arr2));

//console.table 꿀팁 얻음!
