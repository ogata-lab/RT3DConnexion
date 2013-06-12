#pragma once

#include <atlstr.h> 
#import "progid:TDxInput.Device.1" no_namespace

class C3DConnexion
{
private:
	CComPtr<ISensor> m_3DSensor;
	CComPtr<IKeyboard> m_3DKeyboard;

private:
	BOOL m_ValidFlag;

public:
	BOOL IsValid() {return m_ValidFlag;}
	HWND m_hWnd;
	void CreateMainWindow (int x, int y, int h, int w, char *caption);

public:

	//�R���g���[���̏��DUpdateData�֐��ōX�V���邱�ƁD
    
	union {
		struct {
			//���i
			double tX;
			double tY;
			double tZ;

			//��]
			double rX;
			double rY;
			double rZ;
		};
		double data[6];
	};


public:
	C3DConnexion(void);
	~C3DConnexion(void);
	
public:
	HRESULT UpdateData(void);
};
