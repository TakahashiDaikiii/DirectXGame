struct VertexShaderOutput
{
    float4 position : SV_Position;
};

struct VertexShaderInput
{
    float4 posision : POSITION0;
};

VertexShaderOutput main(VertexShaderInput input)
{
    VertexShaderOutput output;
    output.position = input.posision;
    return output;
}