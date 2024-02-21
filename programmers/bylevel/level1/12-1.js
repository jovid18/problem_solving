function solution(a, b) {
    let result = '';
    let sum = 0;

    // a가 b보다 큰 경우, a와 b를 swap하여 정상적인 범위를 만듭니다.
    if (a > b) {
        let temp = a;
        a = b;
        b = temp;
    }

    for (let i = a; i <= b; i++) {
        result += i + '';
    }

    for (let j = 0; j < result.length; j++) {
        sum += parseInt(result[j]);
    }

    console.log(result);
    console.log("합은? : " + sum);

    return sum;
}