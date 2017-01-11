#pragma once

#include"HaselAlias.h"

namespace hasel
{
	namespace shape
	{
		class ShapeBase;

		/// <summary>
		/// �`��N���X
		/// </summary>
		class Shape
		{
		private:
			//�`��C���X�^���X
			sptr<ShapeBase> shape;

		public:
			Shape();

			Shape(const sptr<ShapeBase>& shape);

			/// <summary>
			/// �C���X�^���X�̐��̃|�C���^���擾����
			/// </summary>
			/// <returns></returns>
			ShapeBase* GetRaw()const;

			Shape Copy();

			ShapeBase* operator->()const;
		};
	}
}