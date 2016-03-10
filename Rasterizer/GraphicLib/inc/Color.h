#ifndef ZJR_COLOR_
#define ZJR_COLOR_

class Color
{
public:
	struct _RGB_
	{
		unsigned char R;
		unsigned char G;
		unsigned char B;

		_RGB_(unsigned char r, unsigned char g, unsigned char b) : R(r), G(g), B(b) {}
	};

	float				r;
	float				g;
	float				b;

	Color();
	Color(float c);
	Color(float _r, float _g, float _b);
	Color(const Color &c);
	~Color();

	Color				operator*(const Color &c) const;
	Color				operator*(float f) const;
	Color				operator/(float f) const;
	Color				operator+(const Color &c) const;
	Color				operator-(const Color &c) const;

	Color&				operator=(const Color &rhs);
	Color&				operator*=(const Color &c);
	Color&				operator*=(float f);
	Color&				operator/=(float f);
	Color&				operator+=(const Color &c);
	Color&				operator-=(const Color &c);

	_RGB_				format() const;
};

namespace Colors
{
    const Color AliceBlue            (0.941176534f, 0.972549081f, 1.000000000f);
    const Color AntiqueWhite         (0.980392218f, 0.921568692f, 0.843137324f);
    const Color Aqua                 (0.000000000f, 1.000000000f, 1.000000000f);
    const Color Aquamarine           (0.498039246f, 1.000000000f, 0.831372619f);
    const Color Azure                (0.941176534f, 1.000000000f, 1.000000000f);
    const Color Beige                (0.960784376f, 0.960784376f, 0.862745166f);
    const Color Bisque               (1.000000000f, 0.894117713f, 0.768627524f);
    const Color Black                (0.000000000f, 0.000000000f, 0.000000000f);
    const Color BlanchedAlmond       (1.000000000f, 0.921568692f, 0.803921640f);
    const Color Blue                 (0.000000000f, 0.000000000f, 1.000000000f);
    const Color BlueViolet           (0.541176498f, 0.168627456f, 0.886274576f);
    const Color Brown                (0.647058845f, 0.164705887f, 0.164705887f);
    const Color BurlyWood            (0.870588303f, 0.721568644f, 0.529411793f);
    const Color CadetBlue            (0.372549027f, 0.619607866f, 0.627451003f);
    const Color Chartreuse           (0.498039246f, 1.000000000f, 0.000000000f);
    const Color Chocolate            (0.823529482f, 0.411764741f, 0.117647067f);
    const Color Coral                (1.000000000f, 0.498039246f, 0.313725501f);
    const Color CornflowerBlue       (0.392156899f, 0.584313750f, 0.929411829f);
    const Color Cornsilk             (1.000000000f, 0.972549081f, 0.862745166f);
    const Color Crimson              (0.862745166f, 0.078431375f, 0.235294133f);
    const Color Cyan                 (0.000000000f, 1.000000000f, 1.000000000f);
    const Color DarkBlue             (0.000000000f, 0.000000000f, 0.545098066f);
    const Color DarkCyan             (0.000000000f, 0.545098066f, 0.545098066f);
    const Color DarkGoldenrod        (0.721568644f, 0.525490224f, 0.043137256f);
    const Color DarkGray             (0.662745118f, 0.662745118f, 0.662745118f);
    const Color DarkGreen            (0.000000000f, 0.392156899f, 0.000000000f);
    const Color DarkKhaki            (0.741176486f, 0.717647076f, 0.419607878f);
    const Color DarkMagenta          (0.545098066f, 0.000000000f, 0.545098066f);
    const Color DarkOliveGreen       (0.333333343f, 0.419607878f, 0.184313729f);
    const Color DarkOrange           (1.000000000f, 0.549019635f, 0.000000000f);
    const Color DarkOrchid           (0.600000024f, 0.196078449f, 0.800000072f);
    const Color DarkRed              (0.545098066f, 0.000000000f, 0.000000000f);
    const Color DarkSalmon           (0.913725555f, 0.588235319f, 0.478431404f);
    const Color DarkSeaGreen         (0.560784340f, 0.737254918f, 0.545098066f);
    const Color DarkSlateBlue        (0.282352954f, 0.239215702f, 0.545098066f);
    const Color DarkSlateGray        (0.184313729f, 0.309803933f, 0.309803933f);
    const Color DarkTurquoise        (0.000000000f, 0.807843208f, 0.819607913f);
    const Color DarkViolet           (0.580392182f, 0.000000000f, 0.827451050f);
    const Color DeepPink             (1.000000000f, 0.078431375f, 0.576470613f);
    const Color DeepSkyBlue          (0.000000000f, 0.749019623f, 1.000000000f);
    const Color DimGray              (0.411764741f, 0.411764741f, 0.411764741f);
    const Color DodgerBlue           (0.117647067f, 0.564705908f, 1.000000000f);
    const Color Firebrick            (0.698039234f, 0.133333340f, 0.133333340f);
    const Color FloralWhite          (1.000000000f, 0.980392218f, 0.941176534f);
    const Color ForestGreen          (0.133333340f, 0.545098066f, 0.133333340f);
    const Color Fuchsia              (1.000000000f, 0.000000000f, 1.000000000f);
    const Color Gainsboro            (0.862745166f, 0.862745166f, 0.862745166f);
    const Color GhostWhite           (0.972549081f, 0.972549081f, 1.000000000f);
    const Color Gold                 (1.000000000f, 0.843137324f, 0.000000000f);
    const Color Goldenrod            (0.854902029f, 0.647058845f, 0.125490203f);
    const Color Gray                 (0.501960814f, 0.501960814f, 0.501960814f);
    const Color Green                (0.000000000f, 0.501960814f, 0.000000000f);
    const Color GreenYellow          (0.678431392f, 1.000000000f, 0.184313729f);
    const Color Honeydew             (0.941176534f, 1.000000000f, 0.941176534f);
    const Color HotPink              (1.000000000f, 0.411764741f, 0.705882370f);
    const Color IndianRed            (0.803921640f, 0.360784322f, 0.360784322f);
    const Color Indigo               (0.294117659f, 0.000000000f, 0.509803951f);
    const Color Ivory                (1.000000000f, 1.000000000f, 0.941176534f);
    const Color Khaki                (0.941176534f, 0.901960850f, 0.549019635f);
    const Color Lavender             (0.901960850f, 0.901960850f, 0.980392218f);
    const Color LavenderBlush        (1.000000000f, 0.941176534f, 0.960784376f);
    const Color LawnGreen            (0.486274540f, 0.988235354f, 0.000000000f);
    const Color LemonChiffon         (1.000000000f, 0.980392218f, 0.803921640f);
    const Color LightBlue            (0.678431392f, 0.847058892f, 0.901960850f);
    const Color LightCoral           (0.941176534f, 0.501960814f, 0.501960814f);
    const Color LightCyan            (0.878431439f, 1.000000000f, 1.000000000f);
    const Color LightGoldenrodYellow (0.980392218f, 0.980392218f, 0.823529482f);
    const Color LightGreen           (0.564705908f, 0.933333397f, 0.564705908f);
    const Color LightGray            (0.827451050f, 0.827451050f, 0.827451050f);
    const Color LightPink            (1.000000000f, 0.713725507f, 0.756862819f);
    const Color LightSalmon          (1.000000000f, 0.627451003f, 0.478431404f);
    const Color LightSeaGreen        (0.125490203f, 0.698039234f, 0.666666687f);
    const Color LightSkyBlue         (0.529411793f, 0.807843208f, 0.980392218f);
    const Color LightSlateGray       (0.466666698f, 0.533333361f, 0.600000024f);
    const Color LightSteelBlue       (0.690196097f, 0.768627524f, 0.870588303f);
    const Color LightYellow          (1.000000000f, 1.000000000f, 0.878431439f);
    const Color Lime                 (0.000000000f, 1.000000000f, 0.000000000f);
    const Color LimeGreen            (0.196078449f, 0.803921640f, 0.196078449f);
    const Color Linen                (0.980392218f, 0.941176534f, 0.901960850f);
    const Color Magenta              (1.000000000f, 0.000000000f, 1.000000000f);
    const Color Maroon               (0.501960814f, 0.000000000f, 0.000000000f);
    const Color MediumAquamarine     (0.400000036f, 0.803921640f, 0.666666687f);
    const Color MediumBlue           (0.000000000f, 0.000000000f, 0.803921640f);
    const Color MediumOrchid         (0.729411781f, 0.333333343f, 0.827451050f);
    const Color MediumPurple         (0.576470613f, 0.439215720f, 0.858823597f);
    const Color MediumSeaGreen       (0.235294133f, 0.701960802f, 0.443137288f);
    const Color MediumSlateBlue      (0.482352972f, 0.407843173f, 0.933333397f);
    const Color MediumSpringGreen    (0.000000000f, 0.980392218f, 0.603921592f);
    const Color MediumTurquoise      (0.282352954f, 0.819607913f, 0.800000072f);
    const Color MediumVioletRed      (0.780392230f, 0.082352944f, 0.521568656f);
    const Color MidnightBlue         (0.098039225f, 0.098039225f, 0.439215720f);
    const Color MintCream            (0.960784376f, 1.000000000f, 0.980392218f);
    const Color MistyRose            (1.000000000f, 0.894117713f, 0.882353008f);
    const Color Moccasin             (1.000000000f, 0.894117713f, 0.709803939f);
    const Color NavajoWhite          (1.000000000f, 0.870588303f, 0.678431392f);
    const Color Navy                 (0.000000000f, 0.000000000f, 0.501960814f);
    const Color OldLace              (0.992156923f, 0.960784376f, 0.901960850f);
    const Color Olive                (0.501960814f, 0.501960814f, 0.000000000f);
    const Color OliveDrab            (0.419607878f, 0.556862772f, 0.137254909f);
    const Color Orange               (1.000000000f, 0.647058845f, 0.000000000f);
    const Color OrangeRed            (1.000000000f, 0.270588249f, 0.000000000f);
    const Color Orchid               (0.854902029f, 0.439215720f, 0.839215755f);
    const Color PaleGoldenrod        (0.933333397f, 0.909803987f, 0.666666687f);
    const Color PaleGreen            (0.596078455f, 0.984313786f, 0.596078455f);
    const Color PaleTurquoise        (0.686274529f, 0.933333397f, 0.933333397f);
    const Color PaleVioletRed        (0.858823597f, 0.439215720f, 0.576470613f);
    const Color PapayaWhip           (1.000000000f, 0.937254965f, 0.835294187f);
    const Color PeachPuff            (1.000000000f, 0.854902029f, 0.725490212f);
    const Color Peru                 (0.803921640f, 0.521568656f, 0.247058839f);
    const Color Pink                 (1.000000000f, 0.752941251f, 0.796078503f);
    const Color Plum                 (0.866666734f, 0.627451003f, 0.866666734f);
    const Color PowderBlue           (0.690196097f, 0.878431439f, 0.901960850f);
    const Color Purple               (0.501960814f, 0.000000000f, 0.501960814f);
    const Color Red                  (1.000000000f, 0.000000000f, 0.000000000f);
    const Color RosyBrown            (0.737254918f, 0.560784340f, 0.560784340f);
    const Color RoyalBlue            (0.254901975f, 0.411764741f, 0.882353008f);
    const Color SaddleBrown          (0.545098066f, 0.270588249f, 0.074509807f);
    const Color Salmon               (0.980392218f, 0.501960814f, 0.447058856f);
    const Color SandyBrown           (0.956862807f, 0.643137276f, 0.376470625f);
    const Color SeaGreen             (0.180392161f, 0.545098066f, 0.341176480f);
    const Color SeaShell             (1.000000000f, 0.960784376f, 0.933333397f);
    const Color Sienna               (0.627451003f, 0.321568638f, 0.176470593f);
    const Color Silver               (0.752941251f, 0.752941251f, 0.752941251f);
    const Color SkyBlue              (0.529411793f, 0.807843208f, 0.921568692f);
    const Color SlateBlue            (0.415686309f, 0.352941185f, 0.803921640f);
    const Color SlateGray            (0.439215720f, 0.501960814f, 0.564705908f);
    const Color Snow                 (1.000000000f, 0.980392218f, 0.980392218f);
    const Color SpringGreen          (0.000000000f, 1.000000000f, 0.498039246f);
    const Color SteelBlue            (0.274509817f, 0.509803951f, 0.705882370f);
    const Color Tan                  (0.823529482f, 0.705882370f, 0.549019635f);
    const Color Teal                 (0.000000000f, 0.501960814f, 0.501960814f);
    const Color Thistle              (0.847058892f, 0.749019623f, 0.847058892f);
    const Color Tomato               (1.000000000f, 0.388235331f, 0.278431386f);
    const Color Transparent          (0.000000000f, 0.000000000f, 0.000000000f);
    const Color Turquoise            (0.250980407f, 0.878431439f, 0.815686345f);
    const Color Violet               (0.933333397f, 0.509803951f, 0.933333397f);
    const Color Wheat                (0.960784376f, 0.870588303f, 0.701960802f);
    const Color White                (1.000000000f, 1.000000000f, 1.000000000f);
    const Color WhiteSmoke           (0.960784376f, 0.960784376f, 0.960784376f);
    const Color Yellow               (1.000000000f, 1.000000000f, 0.000000000f);
    const Color YellowGreen          (0.603921592f, 0.803921640f, 0.196078449f);
}

#endif
