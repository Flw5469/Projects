#using <system.drawing.dll>

using namespace System;
using namespace System::Drawing;

protected:
    virtual Void Form1::OnPaint(PaintEventArgs^ pe) override
    {
        Graphics^ g = pe->Graphics;
        Image^ image = Image::FromFile("SampleImage.jpg");
        Form::ClientSize = image->Size;
        g->DrawImage(image, 0, 0, image->Size.Width, image->Size.Height);
    }