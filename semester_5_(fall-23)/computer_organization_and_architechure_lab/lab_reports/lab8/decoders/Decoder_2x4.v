module Decoder_2x4(A, B, E, I);

    input A, B, E;
    output [3: 0]I; // 3 inputs

    wire nA, nB;

    not n1(nA, A);
    not n2(nB, B);

    and a1(I[0], nA, nB, E);
    and a2(I[1], nA, B, E);
    and a3(I[2], A, nB, E); 
    and a4(I[3], A, B, E);

endmodule
